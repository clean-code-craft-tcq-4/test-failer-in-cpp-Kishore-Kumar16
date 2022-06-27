#include "alerter_test.hpp"

int alerter_stub::networkAlertStub(float celcius) {

    int retval = ALERT_NOT_OK;

    std::cout << "ALERT: Temperature is " << celcius << " celcius.\n";

    if(celcius <= MAX_CELCIUS_THRES) {

        retval = ALERT_OK;
    }

    return retval;
}