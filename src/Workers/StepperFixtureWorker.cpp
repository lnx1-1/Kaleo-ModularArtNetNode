//
// Created by lnx on 28.01.2026.
//

#include "StepperFixtureWorker.h"

#include "FastAccelStepper.h"
#define MAX_SPEED 3000 // Max speed in Steps per second

StepperFixtureWorker::StepperFixtureWorker(const Fixture &fixture) : Idmx_FixtureWorker() {
    Log.verboseln("Setting up Stepper Fixture Worker on Step: %d Dir: %d using RMT", PIN_STEP,
                  PIN_DIRECTION);
    _fixture = fixture;
    _engine = FastAccelStepperEngine();
    _engine.init();


    _stepper = _engine.stepperConnectToPin(PIN_STEP);
    // pinMode(PIN_STEP, OPEN_DRAIN);
    if (_stepper) {
        _stepper->setDirectionPin(PIN_DIRECTION);
        _stepper->setSpeedInUs(1000);
        _stepper->setAcceleration(500);
    }
    _isConnected = true; // Stepper on pins is always "connected" in this context
}


void StepperFixtureWorker::tick() {
}

void StepperFixtureWorker::SendValues(const uint8_t *data, size_t size) {
    if (checkParamsValid(data, &size) && stateValid()) {
        if (size >= 2) {
            float speedFactor = static_cast<double>(MAX_SPEED) / 255.0;
            float scaledSpeed = speedFactor * data[0];
            auto delayInUs = static_cast<uint32_t>(1000000.0f / scaledSpeed);
            _stepper->setSpeedInUs(delayInUs);


            if (data[1] >= 128) {
                Log.verboseln("Mov Right Speed [%F]", scaledSpeed);
                _stepper->runForward();
            } else {
                Log.verboseln("Mov Left Speed [%F]", scaledSpeed);
                _stepper->runBackward();
            }

            if (data[0] == 0) {
                _stepper->stopMove();
                Log.verboseln("Zero Speed - Stopping");
            }
        }
    }
}
