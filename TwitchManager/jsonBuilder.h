#pragma once

// Ensure the nlohmann/json library is available in your project.
// If using vcpkg, install with: vcpkg install nlohmann-json
// Or, download json.hpp from https://github.com/nlohmann/json/releases and place it in your include path.

#include <nlohmann/json.hpp>
#include <string>

using json = nlohmann::json;

class JsonBuilder
{
public:
    JsonBuilder();

    // Add any type
    template<typename T>
    JsonBuilder& add(const std::string& key, const T& value)
    {
        body[key] = value;
        return *this;
    }

    // Add only if condition is true
    template<typename T>
    JsonBuilder& addIf(
        bool condition,
        const std::string& key,
        const T& value)
    {
        if (condition)
        {
            body[key] = value;
        }

        return *this;
    }

    // Get raw json object
    json build() const;

    // Get serialized string
    std::string dump(int indent = -1) const;

private:
    json body;
};