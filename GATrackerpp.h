

#pragma once

#include <string>
class GATrackerpp {

public:
    GATrackerpp(const std::string & trackinkId, const std::string & clientId);

    ~GATrackerpp();

    void sendEvent(const std::string & eventCategory, const std::string & eventAction);

private:
    const std::string trackingId_;
    const std::string clientId_;
};