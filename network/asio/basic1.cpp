#include <iostream>
#include <boost/asio.hpp>
using boost::asio::ip::tcp;
int main()
{
    boost::asio::io_service io;

    boost::asio::deadline_timer t(io, boost::posix_time::milliseconds(10));

    t.wait();
    tcp::resolver  resolver(io);
    tcp::resolver::query query("www.yahoo.com", "80");
    tcp::resolver::iterator iterator = resolver.resolve(query);
    tcp::endpoint ep = *iterator;
    std::cout << ep.address().to_string() << std::endl;

    std::cout << "Hello, world!\n";

    return 0;
}
