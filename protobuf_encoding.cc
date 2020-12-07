#include <fstream>
#include <iostream>
#include "example.pb.h"

int main(int argc, char const *argv[])
{
    //varify the version of library that we link against is
    //compatible with the version of the header we compiled against
    GOOGLE_PROTOBUF_VERIFY_VERSION;
    //fill velues of data
    example::AddressBook address_book;
    example::Person *person = address_book.add_people();
    person->set_name("zhanghy");
    person->set_age(27);
    person->set_height(180.0);

    example::Person_PhoneNumber *number = person->add_phones();
    number->set_number("18700000000");
    number->set_type(1);

    //encoding data and write to local file(the same approach would be used to write the data to the output stream of a network connection.)
    std::fstream f_out("../encoding_cpp.pbuf", std::ios::out | std::ios::trunc | std::ios::binary);
    if (!address_book.SerializePartialToOstream(&f_out))
    {
        std::cerr << "Failed to write adress book" << std::endl;
    }

    //Optional: Delete add global objects allocated by protobuf
    google::protobuf::ShutdownProtobufLibrary();
    return 0;
}
