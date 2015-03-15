
#include <string>
#include <iostream>
#include <sstream>
#include "GATrackerpp.h"

int main() {

    {
        GATrackerpp myTracker("UA-00000000-1", "71798b3b-97af-433e-a83a-fc95f95e50f1");

        for (int i = 0; i < 10; i++) {

            std::stringstream sstm;
            sstm << "MyFirstEvent" << i;
            std::string eventName = sstm.str();
            myTracker.sendAppView("MyDemoApp", "v1","Main screen");
            myTracker.sendEvent("Testing", eventName, i==0 ,i == 4);

            if ( i % 2 ){
                myTracker.sendAppView("MyDemoApp", "v1","Screen 1");
                myTracker.sendEvent("Testing", "Event 1", i==0 ,i == 4);
            }else {
                myTracker.sendAppView("MyDemoApp", "v1","Screen 2");
                myTracker.sendEvent("Testing", "Event 2", i==0 ,i == 4);
            }
        }
    }
    return 0;
}