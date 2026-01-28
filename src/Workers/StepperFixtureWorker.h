//
// Created by lnx on 28.01.2026.
//

#ifndef KALEO_MODULARARTNETNODE_STEPPERFIXTUREWORKER_H
#define KALEO_MODULARARTNETNODE_STEPPERFIXTUREWORKER_H
#include "FastAccelStepper.h"
#include "Idmx_FixtureWorker.h"
#include "../Drivers/RMTStepperDriver.h"

#define PIN_STEP 33
#define PIN_DIRECTION 5
#define PULS_REVOLUTION 1600 // Steps per revolution for the stepper motor

class StepperFixtureWorker : public Idmx_FixtureWorker {
    FastAccelStepperEngine _engine{};
    FastAccelStepper *_stepper{};

public:
    explicit StepperFixtureWorker(const Fixture &fixture);

    void tick() override;

    void SendValues(const uint8_t *data, size_t size) override;
};
#endif //KALEO_MODULARARTNETNODE_STEPPERFIXTUREWORKER_H
