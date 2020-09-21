//
//  client.cc
//
//  Copyright (c) 2019 Yuji Hirose. All rights reserved.
//  MIT License
//

#include <httplib.h>
#include <iostream>
#include <string>

#define CA_CERT_FILE "./ca-bundle.crt"

using namespace std;

int main(int argc , char **argv) {

  string url{*++argv};
  cout<<"url="<<url<<endl;
  
#ifdef CPPHTTPLIB_OPENSSL_SUPPORT
  cout<<"ssl"<<endl;
  //httplib::SSLClient cli("localhost", 8080);
  //httplib::SSLClient cli("google.com");
  httplib::SSLClient cli(url);
  cli.set_ca_cert_path(CA_CERT_FILE);
  cli.enable_server_certificate_verification(true);
#else
  httplib::Client cli("localhost", 80);
#endif

  if (auto res = cli.Get("/hi")) {
    cout << res->status << endl;
    cout << res->get_header_value("Content-Type") << endl;
    cout << res->body << endl;
  } else {
    cout << "error code: " << res.error() << std::endl;
#ifdef CPPHTTPLIB_OPENSSL_SUPPORT
    auto result = cli.get_openssl_verify_result();
    if (result) {
      cout << "verify error: " << X509_verify_cert_error_string(result) << endl;
    }
#endif
  }

  return 0;
}
