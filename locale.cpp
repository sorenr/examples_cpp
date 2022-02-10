#include <iostream>
#include <sstream>
#include <ctime>
#include <iomanip>

int main(int argc, const char * argv[]) {
    const std::string s_locale = setlocale(LC_ALL, "");
    std::cout << "Locale according to setlocale: " << s_locale << std::endl;

    std::cout << "LC_ALL: " << setlocale(LC_ALL, NULL) << std::endl;
    std::cout << "LC_CTYPE: " << setlocale(LC_CTYPE, NULL) << std::endl;

    // Uncomment one of these to instantiate locale for a specific place
    // std::locale here("De_DE");
    // std::locale here("ru_RU");
    // std::locale here("fr_FR");
    // std::locale here("en_US.UTF-8");
    // std::locale here("ja_JP.UTF-8");

    std::locale here( s_locale );
    std::cout << "Initial locale: " << here.name() << std::endl;

    // The first argument is the locale that we're switching to
    if ( argc > 1 ) {
        std::cout << "Imbuing with locale " << argv[1] << std::endl;
        here = std::locale( argv[1] );
    }

    // imbue the string with the locale
    std::stringstream ss_time;
    ss_time.imbue( here );
    std::cout << "The stream locale is: " << ss_time.getloc().name() << std::endl;

    // get the current time and convert it to the local time
    const std::time_t rawtime = std::time(nullptr);
    std::tm time_l;
    localtime_r( &rawtime, &time_l );

    // Print the time
    // https://en.cppreference.com/w/cpp/io/manip/put_time
    ss_time << std::put_time( &time_l, "%a %x %T");
    std::cout << "The time is now: " << ss_time.str() << std::endl;

    // Print the time another way
    ss_time.str("");
    ss_time << std::put_time( &time_l, "%Ec");
    std::cout << "Or alternatively: " << ss_time.str() << std::endl;

    return 0;
}
