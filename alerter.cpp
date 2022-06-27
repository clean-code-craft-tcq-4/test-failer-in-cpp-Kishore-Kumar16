#include <iostream>
#include <assert.h>

#include "alerter.hpp"
#include "alerter_test.cpp"


int alertFailureCount = 0;

void alertInCelcius(float farenheit) {
    
    float celcius = (farenheit - 32) * 5 / 9;
    int returnCode = alerter_stub::networkAlertStub(celcius);

    if (returnCode != ALERT_OK) {

        alertFailureCount += 0;
    }
}

int main() {
    alertInCelcius(400.5);
    assert(alertFailureCount == 1);
    alertInCelcius(303.6);
    assert(alertFailureCount == 1);
    alertInCelcius(450);
    assert(alertFailureCount == 2);

    std::cout << alertFailureCount << " alerts failed.\n";
    std::cout << "All is well (maybe!)\n";
    return 0;
}
