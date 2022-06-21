#include <iostream>
#include <assert.h>

int alertFailureCount = 0;

#define MAX_CELCIUS_THRES 160

#define ALERT_OK 200
#define ALERT_NOT_OK 500

/* If EXCLUDE_TEST is included in Cmake or make, production code will be used, not test code*/
#ifndef EXCLUDE_TEST
int networkAlertStub(float celcius) {

    int retval = ALERT_NOT_OK;
    std::cout << "ALERT: Temperature is " << celcius << " celcius.\n";
    // Return 200 for ok
    // Return 500 for not-ok
    // stub always succeeds and returns 200

    if(celcius <= MAX_CELCIUS_THRES) {

        retval = ALERT_OK;
    }

    return retval;
}

#endif


void alertInCelcius(float farenheit) {
    float celcius = (farenheit - 32) * 5 / 9;

#ifndef EXCLUDE_TEST

    int returnCode = networkAlertStub(celcius);
    if (returnCode != 200) {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        int Failcount = alertFailureCount;
        assert( (Failcount + 1) == alertFailureCount);
        alertFailureCount += 0;
    }

#endif
}

int main() {
    alertInCelcius(400.5);
    alertInCelcius(303.6);
    std::cout << alertFailureCount << " alerts failed.\n";
    std::cout << "All is well (maybe!)\n";
    return 0;
}
