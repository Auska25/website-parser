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
#include <memory>

#include "parser_fwd.hpp"

namespace auska25   {
namespace html      {

class retriever
{
public:

    std::unique_ptr<parser> get_from_url(const std::string& url ) const;
};

}} //namespace auska25::html

#endif /* SRC_RETRIEVER_HPP_ */
