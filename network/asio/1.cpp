#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <iostream>
#include <string>
using namespace boost::asio;
io_service service;
ip::tcp::endpoint ep(ip::address::from_string("127.0.0.1"), 8001);
using error_code = boost::system::error_code;
size_t read_complete(char* buf, const error_code& err, size_t bytes){
    if(err)return 0;
    bool found = std::find(buf, buf + bytes, '\n') < buf + bytes;
    return found ? 0 : 1;
}
void sync_echo(std::string msg){
    msg += '\n';
    ip::tcp::socket sock(service);
    sock.connect(ep);
    sock.write_some(buffer(msg));
    char buf[1024];
    int bytes = read(sock, buffer(buf), boost::bind(read_complete, buf, _1, _2));
    std::string copy(buf, bytes - 1);
    msg = msg.substr(0, msg.size() - 1);
    std::cout << "server echoed our " << msg << " : " << (copy == msg ? "OK" : "FAIL") << std::endl;
    sock.close();
}

int main (){
    char* msg[] = {"day one ", "day two"};
    boost::thread_group threads;
    for(char** message = msg; *message; ++message){
        threads.create_thread(boost::bind(sync_echo *message));
        boost::this_thread::sleep(boost::posix_time::millisec(100));

    }
    threads.join_all();
    return 0;
}