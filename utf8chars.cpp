#include <fstream>  // ifstream
#include <iostream> // stdout
#include <codecvt>  // utf8conv
#include <cstring>  // strerror

// Write each line char by char
size_t print_str( const std::string* const line )
{
    std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> utf8conv;
    std::u32string wstr = utf8conv.from_bytes(*line);
    for (std::u32string::const_iterator si = wstr.begin(); si < wstr.end(); si++)
    {
        std::cout << "[" << utf8conv.to_bytes(*si) << "] ";
    }
    std::cout << std::endl;
    std::cout << line->length() << " bytes, " << wstr.length() << " chars." << std::endl;
    return wstr.length();
}

// Write each line from a file
int print_file( const char* const fname )
{
    std::ifstream fh(fname);

    if (fh.fail())
    {
        std::cerr << fname << " " << std::strerror(errno) << std::endl;
        return errno;
    }

    int ln = 0;
    for( std::string line; getline( fh, line ); )
    {
        std::cout << "Line " << ++ln << "" << std::endl;
        print_str( &line );
        std::cout << std::endl;
    }

    return 0;
}

// Write each file from argv
int main(int argc, char **argv) {
    for ( int i=1; i<argc; i++ )
    {
        if ( int rv = print_file(argv[i]) )
        {
            return rv;
        }
    }
    return 0;
}
