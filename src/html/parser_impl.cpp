/*
 * parser_impl.cpp
 *
 *  Created on: 9 Jul 2015
 *      Author: karl
 */
#include <cstring>

#include <libxml/HTMLparser.h>

#include "parser_impl.hpp"

using namespace auska25::html;

namespace
{

const std::string HTTP_STRING_SLASHES       = "http://";
const std::string HTTP_STRING_NO_SLASHES    = "http:";
const std::string DOUBLE_SLASHES            = "//";
const std::string SINGLE_SLASH              = "/";

std::string get_domain_from_url(const std::string& url)
{
    size_t pos = url.find('/', HTTP_STRING_SLASHES.length());

    return (pos != std::string::npos) ? url.substr(0, pos) : url;
}

void sanitise_link(std::string& link, const std::string& url)
{
    if (link.compare(0,DOUBLE_SLASHES.length(), DOUBLE_SLASHES) == 0)
    {
        link.insert(0, HTTP_STRING_NO_SLASHES);
    }
    else if( link.compare(0, SINGLE_SLASH.length(), SINGLE_SLASH) == 0)
    {
        link.insert(0, get_domain_from_url(url));
    }
}

} // namespace

parser_impl::parser_impl( std::unique_ptr<std::ostringstream>& html , std::string url) :
        root_(nullptr),
        html_(std::move(html)),
        doc_(nullptr),
        url_(url)
{
    create_tree();
    parse_links();
}

parser_impl::~parser_impl()
{
    delete root_;
    xmlFreeDoc(doc_);
}

void parser_impl::create_tree()
{
    // Parse HTML and create a DOM tree
    doc_ = htmlReadDoc((xmlChar*)html_->str().c_str(), NULL, NULL, HTML_PARSE_RECOVER | HTML_PARSE_NOERROR | HTML_PARSE_NOWARNING);

    // Encapsulate raw libxml document in a libxml++ wrapper
    xmlNode* r = xmlDocGetRootElement(doc_);
    root_ = new xmlpp::Element(r);
}

void parser_impl::parse_links()
{
    std::string xpath = "//a/@href";
    auto elements = root_->find(xpath);

    for(auto&& i : elements)
    {
        if( i->get_name().compare("href") == 0 )
        {
            auto children = i->get_children();

            for(auto&& j : children)
            {
                if( j->get_name().compare("text") == 0 )
                {
                    std::string link = ((xmlpp::ContentNode*)j )->get_content();
                    sanitise_link(link, url_);
                    links_.push_back(link);
                }
            }
        }
    }
}

void parser_impl::dump(std::ostream& out)
{
    out << html_->str() << std::endl;

    out << "Links:" << std::endl;

    for(auto&& i : links_)
    {
        out << i << std::endl;
    }
}






