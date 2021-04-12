// on Ubuntu: sudo apt-get install libpoco-dev
// or see http://pocoproject.org/
// compile with: g++ -Wall -O3 send-mail-cxx.C -lPocoNet -lPocoFoundation

#include <Poco/Net/MailMessage.h>
#include <Poco/Net/SMTPClientSession.h>
#include <cstdlib>
#include <iostream>
#include <string>

namespace config {
constexpr std::string_view SMTP_SERVER_NAME = "smtp-spb-00.obit.ru";
}

int main()
{
    try {
        Poco::Net::MailMessage msg;

        msg.addRecipient(Poco::Net::MailRecipient(Poco::Net::MailRecipient::PRIMARY_RECIPIENT,
            "i.orfanidi@mail.ru",
            "Иван Орфаниди"));

        msg.setSender("Ivan Orfanidi <i.orfanidi@mail.ru>");
        msg.setSubject("Raspberry Pi");

        msg.setContent("Sending mail from C++ using POCO C++ Libraries");

        Poco::Net::SMTPClientSession smtp(config::SMTP_SERVER_NAME.data());
        smtp.open();
        smtp.login();
        smtp.sendMessage(msg);
        smtp.close();
        std::cout << "Sent mail successfully!" << std::endl;
    } catch (std::exception& e) {
        std::cerr << "failed to send mail: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}