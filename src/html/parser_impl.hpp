/*
 * parser_impl.hpp
 *
 *  Created on: 9 Jul 2015
 *      Author: karl
 */

#ifndef SRC_HTML_PARSER_IMPL_HPP_
#define SRC_HTML_PARSER_IMPL_HPP_

#include <libxml++/libxml++.h>

#include "parser.hpp"

namespace auska25   {
namespace html      {

class parser_impl : public parser
{
private:
    std::unique_ptr<std::ostringstream>  html_;
    xmlpp::Element*     root_;

    void parse();

public:
    explicit parser_impl( std::unique_ptr<std::ostringstream>& html );

    ~parser_impl();

    virtual void dump(std::ostream& out);
};

}} //namespace auska25::html

#endif /* SRC_HTML_PARSER_IMPL_HPP_ */
