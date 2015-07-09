/*
 * parser.hpp
 *
 *  Created on: 9 Jul 2015
 *      Author: karl
 */

#ifndef SRC_HTML_PARSER_HPP_
#define SRC_HTML_PARSER_HPP_

#include "parser_fwd.hpp"

namespace auska25   {
namespace html      {

class parser
{
public:

    virtual ~parser()
    {
        // do nothing
    };

    virtual void dump(std::ostream& out) = 0;
};

}} //namespace auska25::html

#endif /* SRC_HTML_PARSER_HPP_ */
