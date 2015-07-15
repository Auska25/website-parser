/*
 * parser_impl.hpp
 *
 *  Created on: 9 Jul 2015
 *      Author: karl
 */

#ifndef SRC_HTML_PARSER_IMPL_HPP_
#define SRC_HTML_PARSER_IMPL_HPP_

#include <libxml/tree.h>
#include <libxml++/libxml++.h>

#include "parser.hpp"

namespace auska25   {
namespace html      {

class parser_impl : public parser
{
private:

    void create_tree();

    void parse_links();

public:
    explicit parser_impl( std::unique_ptr<std::ostringstream>& html, std::string url );

    ~parser_impl();

    virtual void dump(std::ostream& out);

private:
    std::unique_ptr<std::ostringstream>     html_;
    xmlDoc*                                 doc_;
    xmlpp::Element*                         root_;
    links_t                                 links_;
    std::string                             url_;
};

}} //namespace auska25::html

#endif /* SRC_HTML_PARSER_IMPL_HPP_ */
