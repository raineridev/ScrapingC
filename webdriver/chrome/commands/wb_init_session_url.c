//Test
#include "../../../scrapingc.h"

void wb_init_session_url() 
{
	CURL *curl = curl_easy_init();
    if (curl) {
        CURLcode res;
		char *url;

		url = embedf("http://localhost:%s%s", PORT_CHROME_WEBDRIVER, INIT_SESSION_URL);
        struct curl_slist *slist1 = NULL;
        slist1 = curl_slist_append(slist1, "Content-Type: application/json");
        slist1 = curl_slist_append(slist1, "Accept: application/json");

        char *json = "{\"capabilities\": {\"alwaysMatch\": {\"browserName\": \"chrome\"}}}";

        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, slist1);
        curl_easy_setopt(curl, CURLOPT_URL, url);
		printf("%s", url);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, json);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
		free(url);
    }
}
