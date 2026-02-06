//
// Created by lnx on 28.01.2026.
//

#include "StepperFixtureWorker.h"
#include "FastAccelStepper.h"

void StepperFixtureWorker::configureSettings() {
    settingsManager->addSetting("max_speed", "Max Speed (Steps/s)", &_settings.maxSpeed, "number");
    settingsManager->addSetting("accel", "Acceleration (Steps/s^2)", &_settings.acceleration, "number");
    settingsManager->addSetting("pulses", "Pulses Per Revolution", &_settings.pulsesPerRevolution, "number");
    settingsManager->load();
}

StepperFixtureWorker::StepperFixtureWorker(const Fixture &fixture) : Idmx_FixtureWorker(fixture) {
    configureSettings();

    Log.verboseln("Setting up Stepper Fixture Worker on Step: %d Dir: %d using RMT", PIN_STEP,
                  PIN_DIRECTION);
    _engine = FastAccelStepperEngine();
    _engine.init();


    _stepper = _engine.stepperConnectToPin(PIN_STEP);
    // pinMode(PIN_STEP, OPEN_DRAIN);
    if (_stepper) {
        _stepper->setDirectionPin(PIN_DIRECTION);
        _stepper->setSpeedInUs(1000000 / _settings.maxSpeed); // Initial speed
        _stepper->setAcceleration(static_cast<int32_t>(_settings.acceleration));
    }
    _isConnected = true; // Stepper on pins is always "connected" in this context
}


void StepperFixtureWorker::tick() {
}

void StepperFixtureWorker::SendValues(const uint8_t *data, size_t size) {
    if (checkParamsValid(data, &size) && stateValid()) {
        if (size >= 2) {
            const float speedFactor = static_cast<float>(_settings.maxSpeed) / 255.0;
            const float scaledSpeed = speedFactor * data[0];

            auto DMX_SpeedVal = data[0];
            auto DMX_DirVal = data[1];

            if (_last_DMXSpeedVal == DMX_SpeedVal) return;


            if (DMX_SpeedVal == 0) {
                _stepper->stopMove();
                Log.traceln("Zero Speed - Stopping");
            } else {
                auto delayInUs = static_cast<uint32_t>(1000000.0f / scaledSpeed);
                _stepper->setSpeedInUs(delayInUs);

                if (DMX_DirVal >= 128) {
                    Log.traceln("Mov Right Speed [%F]", scaledSpeed);
                    _stepper->runForward();
                } else {
                    Log.traceln("Mov Left Speed [%F]", scaledSpeed);
                    _stepper->runBackward();
                }
            }
            _last_DMXSpeedVal = DMX_SpeedVal;
        }
    }
}

void StepperFixtureWorker::onSettingsChanged(const String &key) {
    if (key == "accel" && _stepper) {
        _stepper->setAcceleration(static_cast<int32_t>(_settings.acceleration));
    }
}
