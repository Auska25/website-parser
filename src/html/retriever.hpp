/*
 * html_retriever.hpp
 *
 *  Created on: 5 Jul 2015
 *      Author: karl
 *
 *  retriever and stores html
 */

#ifndef SRC_RETRIEVER_HPP_
#define SRC_RETRIEVER_HPP_

#include <string>
#include <sstream>
#include <vector>

#include <libxml/tree.h>
#include <libxml/HTMLparser.h>
#include <libxml++/libxml++.h>

namespace auska25   {
namespace html      {

class retriever
{
private:
    std::ostringstream  html_;
    xmlpp::Element*     root_;
public:
    explicit retriever( std::string& url );

    void dump(std::ostream& out);

    void parse();
};

}} //namespace auska25::html

#endif /* SRC_RETRIEVER_HPP_ */
