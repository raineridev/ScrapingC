#include "scrapingc.h"

int main(void) 
{
    wb_init_session_url();
    CURL *curl = curl_easy_init();
    if(curl) {
        CURLcode res;
        struct curl_slist *slist1 = NULL;
        slist1 = curl_slist_append(slist1, "Content-Type: application/json");
        slist1 = curl_slist_append(slist1, "Accept: application/json");

        char *json = "{\"url\": \"https://lista.mercadolivre.com.br\"}";

        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, slist1);
        curl_easy_setopt(curl, CURLOPT_URL, "http://localhost:9515/session/ee2ae48f607b6282c3e02da15f258005/url");
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, json);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }
    return (0);
}