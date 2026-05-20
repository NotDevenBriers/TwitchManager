#include "jsonBuilder.h"
#include <iostream>


int main() {

	//testing dynamic json building

    std::string title = "game analysis 1v1";
    int cost = 50000;

    std::string prompt = "Challenge the streamer";
    bool usePrompt = true;

    JsonBuilder builder;

    builder
        .add("title", title)
        .add("cost", cost)
        .addIf(usePrompt, "prompt", prompt)
        .addIf(true, "is_enabled", true);

    std::string jsonBody = builder.dump(4);

    std::cout << jsonBody << std::endl;


	return 0;
}