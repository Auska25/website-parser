/*
 * html_retriever.cpp
 *
 *  Created on: 5 Jul 2015
 *      Author: karl
 */

#include "retriever.hpp"

#include <curlpp/cURLpp.hpp>
#include <curlpp/Options.hpp>

using namespace auska25;

using std::string;
using curlpp::options::Url;

html::retriever::retriever(string& url) :
        root_(NULL)
{
    html_ << Url(url);
}

void html::retriever::dump(std::ostream& out)
{
    out << html_.str();
}

void html::retriever::parse()
{
    // Parse HTML and create a DOM tree
    xmlDoc* doc = htmlReadDoc((xmlChar*)html_.str().c_str(), NULL, NULL, HTML_PARSE_RECOVER | HTML_PARSE_NOERROR | HTML_PARSE_NOWARNING);

    // Encapsulate raw libxml document in a libxml++ wrapper
    xmlNode* r = xmlDocGetRootElement(doc);
    xmlpp::Element* root = new xmlpp::Element(r);
}

