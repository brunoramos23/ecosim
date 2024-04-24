#define CROW_MAIN
#define CROW_STATIC_DIR "../public"

#include "crow_all.h"
#include "Board.hpp"
#include "json.hpp"
#include <random>
#include <iostream>
#include <memory>

//static constexpr uint32_t NUM_ROWS = 15;

// Type definitions

// Auxiliary code to convert the entity_type_t enum to a string
NLOHMANN_JSON_SERIALIZE_ENUM(entity_type_t, {
                                                {empty, " "},
                                                {plant, "P"},
                                                {herbivore, "H"},
                                                {carnivore, "C"},
                                            })

// Auxiliary code to convert the entity_t struct to a JSON object
namespace nlohmann
{
    void to_json(nlohmann::json &j, const BoardSerializer &e)
    {
        j = nlohmann::json{{"type", e.type}, {"energy", e.energy}, {"age", e.age}};
    }
}

int main()
{
    crow::SimpleApp app;

    std::shared_ptr<Board> board;

    // Endpoint to serve the HTML page
    CROW_ROUTE(app, "/")
    ([](crow::request &, crow::response &res)
    {
        res.set_static_file_info_unsafe("./public/index.html");
        res.end();
    });

    CROW_ROUTE(app, "/start-simulation")
        .methods("POST"_method)([&board](crow::request &req, crow::response &res)
        { 
            // Parse the JSON request body
            nlohmann::json request_body = nlohmann::json::parse(req.body);

            // Validate the request body 
            uint32_t total_entinties = (uint32_t)request_body["plants"] + (uint32_t)request_body["herbivores"] + (uint32_t)request_body["carnivores"];
            if (total_entinties > ((uint32_t)request_body["dimension"] * (uint32_t)request_body["dimension"])) {
            res.code = 400;
            res.body = "Too many entities";
            res.end();
            return;
            }

            board.reset(new Board((uint32_t)request_body["dimension"], (uint32_t)request_body["plants"], (uint32_t)request_body["herbivores"], (uint32_t)request_body["carnivores"]));
            
            // Create the entities
            // <YOUR CODE HERE>

            // Return the JSON representation of the entity grid
            nlohmann::json json_grid = board->Serialize(); 
            res.body = json_grid.dump();
            res.end(); 
        });

    // Endpoint to process HTTP GET requests for the next simulation iteration
    CROW_ROUTE(app, "/next-iteration")
        .methods("GET"_method)([&board]()
        {
            // Simulate the next iteration
            // Iterate over the entity grid and simulate the behaviour of each entity
            
            // <YOUR CODE HERE>
            board->Advance();

            // Return the JSON representation of the entity grid
            nlohmann::json json_grid = board->Serialize(); 
            return json_grid.dump();
        });
    app.bindaddr("127.0.0.1").port(8080).run();

    return 0;
}