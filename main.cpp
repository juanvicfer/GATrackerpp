
#include <iostream>
#include "GATrackerpp.h"

int main() {
    GATrackerpp myTracker("UA-XXXXXXXX-1","555");

    for( int i = 0; i < 10; i++){
        myTracker.sendEvent("Testing","MyFirstEvent");
    }

    return 0;
}