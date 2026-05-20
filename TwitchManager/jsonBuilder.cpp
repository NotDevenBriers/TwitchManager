#include "jsonBuilder.h"

JsonBuilder::JsonBuilder()
{
    body = json::object();
}

json JsonBuilder::build() const
{
    return body;
}

std::string JsonBuilder::dump(int indent) const
{
    return body.dump(indent);
}