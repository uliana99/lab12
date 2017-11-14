#include <iostream>
#include <curl/curl.h>

int main(int argc, char const *argv[]) {
	std::string console_url;
    CURL *curl = curl_easy_init();
    CURLcode res;

    while(std::cin >> console_url) {
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, false); //  Отменяем проверку сертификата
        curl_easy_setopt(curl, CURLOPT_NOBODY, true); //  Отменяем вывод содержимого страницы
        curl_easy_setopt(curl, CURLOPT_URL, console_url.c_str() ); //  Передаем адрес url необходимого сайта

        res = curl_easy_perform(curl);

        // Проверяем на ошибку
        if(res == CURLE_OK) {

            long response_code;
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
            std::cout << "\tResponse code for URL( " << console_url << " ):\t" << response_code << std::endl;

        } else {
            std::cout << "Error:\t" << curl_easy_strerror(res) << std::endl;
        }
    }

    curl_easy_cleanup(curl);

    return 0;
}