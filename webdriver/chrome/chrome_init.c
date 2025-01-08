#include "../../scrapingc.h"

void	chrome_init()
{
	system("chromedriver --port=9515 > /dev/null");
}
