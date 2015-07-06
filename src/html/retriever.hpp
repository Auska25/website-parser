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

namespace auska25   {
namespace html      {

class retriever
{
public:
    explicit retriever( std::string& url );
};

}} //namespace auska25::html

#endif /* SRC_RETRIEVER_HPP_ */
