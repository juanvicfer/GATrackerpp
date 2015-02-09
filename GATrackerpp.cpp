
#include "GATrackerpp.h"

#include <sstream>
#include <curl/curl.h>

GATrackerpp::GATrackerpp(const std::string & trackingId, const std::string & clientId):
trackingId_(trackingId),clientId_(clientId) {

    curl_global_init(CURL_GLOBAL_ALL);

}

GATrackerpp::~GATrackerpp() {
    curl_global_cleanup();
}

void GATrackerpp::sendEvent(const std::string & eventCategory, const std::string & eventAction){

    CURL * curl = curl_easy_init();
    if(curl) {

        // First set the URL
        //
        curl_easy_setopt(curl, CURLOPT_URL, "https://www.google-analytics.com/collect");

        curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);

        //Now specify event POST data
        //
        std::stringstream postFields;
        postFields << "v=1&tid=" << trackingId_ << "&cid=" << clientId_;
        postFields << "&t=event&ec=" << eventCategory <<  "&ea=" << eventAction;

        std::string postFieldsString = postFields.str();

        printf("Posting with the following fields: %s\n", postFieldsString.c_str());

        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postFields.str().c_str());

        //Perform the request, res will get the return code
        //
        CURLcode res = curl_easy_perform(curl);

        /* Check for errors */
        if(res != CURLE_OK){
            printf("curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }
        else{
            printf("curl_easy_perform() success\n");
        }

        curl_easy_cleanup(curl);
    }
}