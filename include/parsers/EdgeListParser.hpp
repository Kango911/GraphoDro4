#ifndef EDGELISTPARSER_HPP
#define EDGELISTPARSER_HPP

#include "Parser.hpp"
#include <string>

class EdgeListParser : public Parser {
public:
    std::unique_ptr<Graph> parse(const std::string& filename) override;
};

#endif