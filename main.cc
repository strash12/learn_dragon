#include <drogon/drogon.h>
using namespace drogon;

typedef std::function<void(const HttpResponsePtr &)> Callback;

void sayHello(const HttpRequestPtr &request, 
Callback &&callback, const std::string &name,const std::string &surname)
{
    auto resp = HttpResponse::newHttpResponse();
    resp->setStatusCode(k200OK);
    resp->setContentTypeCode(CT_TEXT_HTML);
    resp->setBody("yours name , " + name + " your surname , " +surname);
    callback(resp);
}


int main() {
    //Set HTTP listener address and port
    drogon::app().addListener("0.0.0.0", 5555);

        drogon::app()
    .registerHandler("/action_page?fname={1}&lname={2}", &sayHello, {Get});

    drogon::app().run();
    return 0;
}
