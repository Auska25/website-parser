/*
 * parser_impl.cpp
 *
 *  Created on: 9 Jul 2015
 *      Author: karl
 */

#include <libxml/HTMLparser.h>

#include "parser_impl.hpp"

using namespace auska25::html;

parser_impl::parser_impl( std::unique_ptr<std::ostringstream>& html ) :
        root_(nullptr),
        html_(std::move(html)),
        doc_(nullptr)
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
                    links_.push_back(((xmlpp::ContentNode*)j )->get_content());
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






