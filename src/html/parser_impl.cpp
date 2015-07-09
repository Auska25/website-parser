/*
 * parser_impl.cpp
 *
 *  Created on: 9 Jul 2015
 *      Author: karl
 */

#include <libxml/tree.h>
#include <libxml/HTMLparser.h>

#include "parser_impl.hpp"

using namespace auska25::html;

parser_impl::parser_impl( std::unique_ptr<std::ostringstream>& html ) :
        root_(nullptr),
        html_(std::move(html))
{
    parse();
}

parser_impl::~parser_impl()
{

}

void parser_impl::parse()
{
    // Parse HTML and create a DOM tree
    xmlDoc* doc = htmlReadDoc((xmlChar*)html_->str().c_str(), NULL, NULL, HTML_PARSE_RECOVER | HTML_PARSE_NOERROR | HTML_PARSE_NOWARNING);

    // Encapsulate raw libxml document in a libxml++ wrapper
    xmlNode* r = xmlDocGetRootElement(doc);
    xmlpp::Element* root = new xmlpp::Element(r);
}

void parser_impl::dump(std::ostream& out)
{
    out << html_->str();
}






