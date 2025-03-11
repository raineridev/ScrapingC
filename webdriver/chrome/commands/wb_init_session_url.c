//Test
#include "../../../scrapingc.h"
// 
size_t *write_chunk(char *ptr, size_t size, size_t nmemb, void *userdata);

void wb_init_session_url() 
{
	CURL *curl = curl_easy_init();
    if (curl) {
        CURLcode res;
		char *url;

        Response response;
        response.text = malloc(1);
        response.size = 0;
		url = embedf("http://localhost:%s%s", PORT_CHROME_WEBDRIVER, INIT_SESSION_URL);
        struct curl_slist *slist1 = NULL;
        slist1 = curl_slist_append(slist1, "Content-Type: application/json");
        slist1 = curl_slist_append(slist1, "Accept: application/json");

        char *json = "{\"capabilities\": {\"alwaysMatch\": {\"browserName\": \"chrome\"}}}";

        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, slist1);
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_chunk);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&response);
		printf("%s", url);
        printf("%s", response.text);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, json);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
		free(url);
    }
}

size_t *write_chunk(char *data, size_t size, size_t nmemb, void *userdata)
{
    size_t realsize = size * nmemb;
    Response *response = (Response *)userdata;
    char *ptr = realloc(response->text, response->size + realsize + 1);
    if(!ptr)
        return (0);
    response->text = ptr;
    memcpy(&(response->text[response->size]), data, realsize);
    response->size += realsize;
    response->text[response->size] = '\0';
    return (realsize);
}