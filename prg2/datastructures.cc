// Datastructures.cc

#include "datastructures.hh"

#include <random>
#include <cmath>
#include <stdexcept>

std::minstd_rand rand_engine; // Reasonably quick pseudo-random generator

template <typename Type>
Type random_in_range(Type start, Type end)
{
    auto range = end-start;
    ++range;

    auto num = std::uniform_int_distribution<unsigned long int>(0, range-1)(rand_engine);

    return static_cast<Type>(start+num);
}

// Modify the code below to implement the functionality of the class.
// Also remove comments from the parameter names when you implement
// an operation (Commenting out parameter name prevents compiler from
// warning about unused parameters on operations you haven't yet implemented.)

Datastructures::Datastructures()
{
    // Replace this comment with your implementation
}

Datastructures::~Datastructures()
{
    // Replace this comment with your implementation
}

int Datastructures::stop_count()
{
    return allStops_.size();
}

void Datastructures::clear_all()
{
    allStops_.clear();
    allRoutes_.clear();
    allTrips_.clear();
}

std::vector<StopID> Datastructures::all_stops()
{
    std::vector<StopID> all_stops;

    for (auto& p: allStops_){
        all_stops.push_back(p.first); // performance of push_back() in a vector is constant
    }

    return all_stops;
}

bool Datastructures::add_stop(StopID id, const Name& name, Coord xy)
{
    Stop stop;
    stop.stop_name = name;
    stop.stop_coord = xy;
    bool if_insert = allStops_.insert({id, stop}).second;
    return if_insert;
}

Name Datastructures::get_stop_name(StopID id)
{
    auto iter = allStops_.find(id);
    if (iter != allStops_.end()) {
        return iter->second.stop_name;
    }

    return NO_NAME;

}

Coord Datastructures::get_stop_coord(StopID id)
{
    // Constant on average, worst case linear in the size of the container.
    auto iter = allStops_.find(id);
    if (iter != allStops_.end()) {
        return iter->second.stop_coord;
    }

    return NO_COORD;

}

std::vector<StopID> Datastructures::stops_alphabetically()
{
    // Replace this comment and the line below with your implementation
    return {NO_STOP};
}

std::vector<StopID> Datastructures::stops_coord_order()
{
    // Replace this comment and the line below with your implementation
    return {NO_STOP};
}

StopID Datastructures::min_coord()
{
    // Replace this comment and the line below with your implementation
    return NO_STOP;
}

StopID Datastructures::max_coord()
{
    // Replace this comment and the line below with your implementation
    return NO_STOP;
}

std::vector<StopID> Datastructures::find_stops(Name const& name)
{
    // Replace this comment and the line below with your implementation
    return {NO_STOP};
}

bool Datastructures::change_stop_name(StopID id, const Name& newname)
{
    // Replace this comment and the line below with your implementation
    return false;
}

bool Datastructures::change_stop_coord(StopID id, Coord newcoord)
{
    // Replace this comment and the line below with your implementation
    return false;
}

bool Datastructures::add_region(RegionID id, const Name &name)
{
    // Replace this comment and the line below with your implementation
    return false;
}

Name Datastructures::get_region_name(RegionID id)
{
    // Replace this comment and the line below with your implementation
    return NO_NAME;
}

std::vector<RegionID> Datastructures::all_regions()
{
    // Replace this comment and the line below with your implementation
    return {NO_REGION};
}

bool Datastructures::add_stop_to_region(StopID id, RegionID parentid)
{
    // Replace this comment and the line below with your implementation
    return false;
}

bool Datastructures::add_subregion_to_region(RegionID id, RegionID parentid)
{
    // Replace this comment and the line below with your implementation
    return false;
}

std::vector<RegionID> Datastructures::stop_regions(StopID id)
{
    // Replace this comment and the line below with your implementation
    return {NO_REGION};
}

void Datastructures::creation_finished()
{
    // Replace this comment with your implementation
    // You don't have to use this method for anything, if you don't need it
}

std::pair<Coord,Coord> Datastructures::region_bounding_box(RegionID id)
{
    // Replace this comment and the line below with your implementation
    return {NO_COORD, NO_COORD};
}

std::vector<StopID> Datastructures::stops_closest_to(StopID id)
{
    // Replace this comment and the line below with your implementation
    return {NO_STOP};
}

bool Datastructures::remove_stop(StopID id)
{
    // Replace this comment and the line below with your implementation
    return false;
}

RegionID Datastructures::stops_common_region(StopID id1, StopID id2)
{
    // Replace this comment and the line below with your implementation
    return NO_REGION;
}


// The operations in phase2

std::vector<RouteID> Datastructures::all_routes()
{
    std::vector<RouteID> all_routes;

    for (auto& p: allRoutes_){
        all_routes.push_back(p.first);
    }

    return all_routes;
}

// If routeid and all the stopids not found or only one stop in the vector, return false
bool Datastructures::add_route(RouteID id, std::vector<StopID> stops)
{   
    // First check if only one stops given, return false
    // performance: constant
    if (stops.size() <= 1){
        return false;
    }

    // Then check if routeid  return false
    // performance: linear O(allRoutes.size) at worst and constant in average
    auto iter_route = allRoutes_.find(id);
    if (iter_route != allRoutes_.end()) {
        return false;
    }

    // Finally check if all the stopIds exsit
    // if some stop id is not found, return false
    // otherwise, save iterator of stop into a vector
    std::vector<std::unordered_map<StopID, Stop>::iterator> stops_iter;

    // performance: O(stops.size * allStops.size), Theta(stops.size)
    for (StopID stop_id : stops){
        auto iter_stop = allStops_.find(stop_id);
        if (iter_stop == allStops_.end()){
            return false;
        }
        stops_iter.push_back(iter_stop);
    }

    // first insert route info to allRoutes
    // Constant on average, worst case linear in the size of the allRoutes.
    allRoutes_.insert({id, stops});

    // Then add edge information to each stop
    // linear O(stops.size)
    for (unsigned int i = 0; i < stops_iter.size() - 1; ++i){
        auto from_stop_iter = stops_iter.at(i);
        auto to_stop_iter = stops_iter.at(i+1);
        JourneyEdge edge;
        edge.to_stop = to_stop_iter->first;
        edge.route_id = id;
        edge.distance = distance(from_stop_iter->second, to_stop_iter->second);
        from_stop_iter->second.edges.push_back(edge);

    }
    return true;
}

std::vector<std::pair<RouteID, StopID>> Datastructures::routes_from(StopID stopid)
{
    // Performance: O(allStops), Theta(1)
    auto iter_stop = allStops_.find(stopid);
    if (iter_stop != allStops_.end()){

        // Define output vector
        std::vector<std::pair<RouteID, StopID>> routes_from_stop;

        // iterate all JourneyEdge stored in allStops_
        // Performance: O(allroutes.size) if all routes run through the given stop
        for (JourneyEdge edge : iter_stop->second.edges){
            routes_from_stop.push_back({edge.route_id, edge.to_stop});
        }

        return routes_from_stop;
    }

    // If stopid not found
    return {{NO_ROUTE, NO_STOP}};
}

// Performance: O(allRoutes_.size)
std::vector<StopID> Datastructures::route_stops(RouteID id)
{
    auto iter_route = allRoutes_.find(id);
    if (iter_route != allRoutes_.end()){
        return iter_route->second;
    }
    return {NO_STOP};
}

// Performance: O(allRoutes.size + allTrips.size + allStops.size)
void Datastructures::clear_routes()
{
    allRoutes_.clear(); // linear
    allTrips_.clear();

    // linear
    for (auto& stop: allStops_ ){
        stop.second.edges.clear();
    }
}


// In this operation, RouteIDs don't matter, can be anything, like NO_ROUTE
// The following 4 operations will print a path(journey), and
// using StopTuple = std::tuple<StopID, RouteID, Distance>;
std::vector<std::tuple<StopID, RouteID, Distance>> Datastructures::journey_any(StopID fromstop, StopID tostop)
{
    // first check if fromstop and tostop exist
    // Performance: O(allStops.size)
    auto iter_fromstop = allStops_.find(fromstop);
    auto iter_tostop = allStops_.find(tostop);

    if (iter_fromstop == allStops_.end() || iter_tostop == allStops_.end()){
        return {{NO_STOP, NO_ROUTE, NO_DISTANCE}};
    }

    // In this operation, I implement the DFS algorithm, and when searched the tostop, return the path
    // Then the performance O(edges.size), which means that all the values in allStops

    // current path
    std::vector<StopTuple> path;
    path.push_back({fromstop, NO_ROUTE,0});

    // create stack to store all the path
    std::stack<std::vector<StopTuple>> stack_path;
    stack_path.push(path);


    // check if the stop that has already been processed(expanded)
    std::unordered_set<StopID> processed;

    while (!stack_path.empty()) {

        // Performance of operation in stack is constant
        path = stack_path.top();
        stack_path.pop();
        // the last stop in this path
        StopTuple last_tuple = path.back();
        StopID last_stop = std::get<0>(last_tuple);
        int last_distance = std::get<2>(last_tuple);

        // if last stop is the desired destination
        // then return the path
        if (last_stop == tostop)
            return path;

        // iterate through all the stops connected to
        // current stop and push new path to stack
        // Performance: O(a stop's edge.size)
        processed.insert(last_stop);

        for (JourneyEdge next_edge: allStops_[last_stop].edges) {
            StopID next_stop = next_edge.to_stop;
            int next_distance = next_edge.distance;

            // requiring that, the stop cannot be processed
            auto if_exist = processed.find (next_stop);
            if (if_exist == processed.end()) {
                std::vector<StopTuple> newpath(path);
                newpath.push_back({next_stop,NO_ROUTE,last_distance+next_distance});
                stack_path.push(newpath);              
            }
        }
    }

    // if no route found, then empty vector should be returned
    path.clear();
    return path;
}

std::vector<std::tuple<StopID, RouteID, Distance>> Datastructures::journey_least_stops(StopID fromstop, StopID tostop)
{
    auto iter_fromstop = allStops_.find(fromstop);
    auto iter_tostop = allStops_.find(tostop);

    if (iter_fromstop == allStops_.end() || iter_tostop == allStops_.end()){
        return {{NO_STOP, NO_ROUTE, NO_DISTANCE}};
    }

    // current path
    std::vector<StopTuple> path;
    path.push_back({fromstop, NO_ROUTE,0});

    // create queue
    std::queue<std::vector<StopTuple>> queue_path;
    queue_path.push(path);

    // implement bfs to get least stops, so the performance is also O(values.size in allStops)
    // check if the stop that has already been discovered
    std::unordered_set<StopID> discovered;
    discovered.insert(fromstop);

    while (!queue_path.empty()) {
        // Performance of operations in queue is constant
        path = queue_path.front();
        queue_path.pop();
        StopTuple last_tuple = path.back();
        StopID last_stop = std::get<0>(last_tuple);
        int last_distance = std::get<2>(last_tuple);

        // if last stop is the desired destination
        // then return the path
        if (last_stop == tostop)
            return path;

        // traverse to all the stops connected to
        // current stop and push new path to queue
        for (JourneyEdge next_edge: allStops_[last_stop].edges) {
            StopID next_stop = next_edge.to_stop;

            // requiring that, the stop cannot be discovered
            auto if_exist = discovered.find (next_stop);
            if (if_exist == discovered.end()) {
                std::vector<StopTuple> newpath(path);
                std::get<1>(newpath.back()) = next_edge.route_id;
                Distance add_distance = next_edge.distance;
                newpath.push_back({next_stop,NO_ROUTE,last_distance+add_distance});
                queue_path.push(newpath);
                discovered.insert(next_stop);
            }
        }
    }

    // if no route found, then empty vector should be returned
    path.clear();
    return path;
}

std::vector<std::tuple<StopID, RouteID, Distance>> Datastructures::journey_with_cycle(StopID fromstop)
{
    auto iter_fromstop = allStops_.find(fromstop);
    if (iter_fromstop == allStops_.end()){
        return {{NO_STOP, NO_ROUTE, NO_DISTANCE}};
    }

    // current path
    std::vector<StopTuple> path;
    path.push_back({fromstop, NO_ROUTE,0});

    // create stack
    std::stack<std::vector<StopTuple>> stack_path;
    stack_path.push(path);

    // implement dfs to find circle, if a node has already been processed but not finished, then find a circle
    // Performance of dfs is O(all values in allStops)
    // check if the stop that has already been processed
    // and if all neigbours are handled (node is finished), then the second value is true
    std::unordered_map<StopID, bool> processed;

    while (!stack_path.empty()) {
        path = stack_path.top();
        stack_path.pop();
        StopTuple last_tuple = path.back();
        StopID last_stop = std::get<0>(last_tuple);

        auto iter = processed.find(last_stop);

        // if this stop has been processed again
        // then this stop is finished
        if (iter != processed.end()){
            iter->second = true;
        }else{
            // make this stop processed
            processed.insert({last_stop,false});

            // push again, for marking as finished
            stack_path.push(path);

            // go through the nighbours
            int last_distance = std::get<2>(last_tuple);

            for (JourneyEdge next_edge: allStops_[last_stop].edges) {
                StopID next_stop = next_edge.to_stop;
                std::vector<StopTuple> newpath(path);
                std::get<1>(newpath.back()) = next_edge.route_id;
                int add_distance = next_edge.distance;
                newpath.push_back({next_stop,NO_ROUTE,last_distance+add_distance});

                auto if_exist = processed.find (next_stop);

                // if the stop is not discovered, then add new path to stack_path
                if (if_exist == processed.end()) {
                    stack_path.push(newpath);
                }else if (processed[next_stop] == false){
                    // if this stop is discovered but not finished, then the circle is found
                    return newpath;
                }
            }

        }

    }

    // if no route found, then empty vector should be returned
    path.clear();
    return path;
}

std::vector<std::tuple<StopID, RouteID, Distance>> Datastructures::journey_shortest_distance(StopID fromstop, StopID tostop)
{
    auto iter_fromstop = allStops_.find(fromstop);
    auto iter_tostop = allStops_.find(tostop);

    if (iter_fromstop == allStops_.end() || iter_tostop == allStops_.end()){
        return {{NO_STOP, NO_ROUTE, NO_DISTANCE}};
    }

    // current path
    std::vector<StopTuple> path;
    path.push_back({fromstop, NO_ROUTE,0});

    // create priorit queue
    my_priority_queue queue_path;
    queue_path.push(path);

    // implement Dijkstra algorithm to find shortest distance
    // The performance of Dijkstra is O((allStops.key.size + allStops.values.size)*lg(allStops.size))

    // check if the stop that has already been discovered
    // if the stop is not discovered, then directly add this stop to the path
    // if this stop is discovered, then should compare the distance
    std::unordered_map<StopID, Distance> discovered;
    discovered.insert({fromstop, 0});

    while (!queue_path.empty()) {

        path = queue_path.top();
        queue_path.pop();

        std::tuple<StopID, RouteID, Distance> last_tuple = path.back();
        StopID last_stop = std::get<0>(last_tuple);
        int last_distance = std::get<2>(last_tuple);

        // if last stop is the desired destination
        // then return the path
        if (last_stop == tostop)
            return path;

        // this step is to remove the path whose total distance > known shortest distance
        // because when I update the shorter distance of one stop in discovered
        // I didn't remove the other path(from start to this stop) from the priority_queue
        if (last_distance > discovered[last_stop]){
            continue;
        }

        // traverse to all the stops connected to the last_stop
        for (JourneyEdge next_edge: allStops_[last_stop].edges) {
            StopID next_stop = next_edge.to_stop;
            Distance new_distance = next_edge.distance + last_distance;

            // if the stop is not discovered
            // or the new_distance is shorter than the known distance
            // push the new path

            auto if_exist = discovered.find(next_stop);
            if (if_exist == discovered.end() || new_distance < discovered[next_stop]) {

                // add this stop to the newpath
                std::vector<StopTuple> newpath(path);
                std::get<1>(newpath.back()) = next_edge.route_id;
                newpath.push_back({next_stop,NO_ROUTE,new_distance});
                queue_path.push(newpath);
                discovered[next_stop] = new_distance;
            }
        }
    }

    // if no route found, then empty vector should be returned
    path.clear();
    return path;
}

bool Datastructures::add_trip(RouteID routeid, std::vector<Time> const& stop_times)
{
    // first, find the route, performance: O(allRoutes.size)
    auto iter_route = allRoutes_.find(routeid);

    if (iter_route != allRoutes_.end()){
        std::vector<StopID> const &stops =  iter_route->second;
        // iterate through the stops along this route. Performance: O(allStops.size)
        for(unsigned int i = 0; i < stops.size()-1; ++i){
            StopID stop_from = stops.at(i);
            TripEdge edge;
            edge.to_stop = stops.at(i+1);
            edge.time_from = stop_times.at(i);
            edge.time_to = stop_times.at(i+1);
            allTrips_[stop_from][routeid].push_back(edge);
        }

        return true;
    }

    // if no routeid exist, then return false
    return false;
}

std::vector<std::pair<Time, Duration>> Datastructures::route_times_from(RouteID routeid, StopID stopid)
{
    // Performance: O(allTrips.size)
    auto iter_stop = allTrips_.find(stopid);
    if (iter_stop != allTrips_.end()){
        // Performance: O(allRoutes.size) if all the routes passing through this given stop
        std::unordered_map<RouteID, std::vector<TripEdge>>::iterator iter_route = (iter_stop->second).find(routeid);
        // if find the route that passing through this stop
        if (iter_route != (iter_stop->second).end()){
            std::vector<std::pair<Time, Duration>> route_times;
            for (TripEdge edge: iter_route->second){
                route_times.push_back({edge.time_from, edge.time_to-edge.time_from});
            }
            return route_times;
        }
    }

    return {{NO_TIME, NO_DURATION}};
}

std::vector<std::tuple<StopID, RouteID, Time> > Datastructures::journey_earliest_arrival(StopID fromstop, StopID tostop, Time starttime)
{
    // First find two stops O(allStops.size)
    auto iter_fromstop = allStops_.find(fromstop);
    auto iter_tostop = allStops_.find(tostop);

    if (iter_fromstop == allStops_.end() || iter_tostop == allStops_.end()){
        return {{NO_STOP, NO_ROUTE, NO_DISTANCE}};
    }

    // current path
    std::vector<TripTuple> path;
    path.push_back({fromstop, NO_ROUTE, starttime});

    // create priorit queue
    my_priority_queue queue_path;
    queue_path.push(path);

    // implement Dijkstra algorithm to find earliest_arrival(the value compared is arrival time of the stop)
    // So it's similiar to the journey_shortest_distance,
    // but the difference is that the distance beween 2 stops is fixed while durations are not same

    // check if the stop that has already been discovered
    // if the stop is not discovered, then directly add this stop to the path
    // if this stop is discovered, then should compare the distance

    // this time is arrival time of the stops
    std::unordered_map<StopID, Time> discovered;
    discovered.insert({fromstop, starttime});

    while (!queue_path.empty()) {

        path = queue_path.top();
        queue_path.pop();

        std::tuple<StopID, RouteID, Time> last_tuple = path.back();
        StopID last_stop = std::get<0>(last_tuple);
        Time  arrival_time = std::get<2>(last_tuple);
        RouteID last_route = NO_ROUTE;

        // the last_route is in the penultimate tuple
        // because the route in last tuple represents the next stop
        if (path.size() > 1)
            RouteID last_route = std::get<1>(path.at(path.size()-2));



        // if last stop is the desired destination
        // then return the path
        if (last_stop == tostop)
            return path;

        // this step is to remove the path whose arrival time > known earliest arrival time
        if (arrival_time > discovered[last_stop]){
            continue;
        }

        // traverse to all the stops connected to the last_stop
        // Performance: O(edges.size)
        for (auto iter = allTrips_[last_stop].begin(); iter != allTrips_[last_stop].end(); ++iter) {
            RouteID next_route = iter->first;
            std::vector<TripEdge> next_times = iter->second;
            StopID next_stop = next_times.at(0).to_stop;

            // My idea: like distance, we need to get arrival time of next_stop, but arrival time is related to the departure time of
            // last stop and the route

           // if the route is not changed, then departure time is same as arrival time and find the arrival time correponding to
           // the departure time.

           // But, if the route is changed, then the departure time probably will be changed,then we need update the time of last tuple
           // Then the new departure time should be smallest among all the time later than arrival time
            Time  last_departure_time = NO_TIME;
            Time next_arrival_time = NO_TIME;

            // if two routes are same, then arrival time to last_stop is same as departural time from last_stop
            if (next_route == last_route){

                // here, don't need to update last_time
                // we should find the to_time corresponding to the the from_time==last_time
                // Performance: O(all time pairs)
                for (TripEdge time: next_times){
                    if (time.time_from == arrival_time){
                       last_departure_time = arrival_time;
                       next_arrival_time = time.time_to;
                       break;
                    }
                }

            }else{
                // if the next_route is changed, then we need to update the departural time(last_time)
                // we need to find a to_time that is greater than last_time, but is the smallest in the vector

                // first remove all the time later than the arrival_time
                for (auto it = next_times.begin(); it != next_times.end();)
                {
                  if (it->time_from < arrival_time)
                    it = next_times.erase(it);
                  else
                    ++it;
                }

                // if all the departural time < arrival time
                // then skip this route
                if (next_times.empty())
                    continue;

                // find the smallest departural time
                std::vector<TripEdge>::iterator earliest_time_iter;
                earliest_time_iter = std::min_element(next_times.begin(), next_times.end(),
                    [](TripEdge const &time1, TripEdge const &time2){
                        return time1.time_from < time2.time_from;});

                last_departure_time = earliest_time_iter->time_from;
                next_arrival_time = earliest_time_iter->time_to;

            }

            // if the stop is not discovered
            // or the new arrival time is smaller than the known earliest arrival time
            // push the new path
            auto if_exist = discovered.find(next_stop);
            if (if_exist == discovered.end() || next_arrival_time < discovered[next_stop]) {
                // add this stop to the newpath
                std::vector<StopTuple> newpath(path);
                std::get<1>(newpath.back()) = next_route;
                std::get<2>(newpath.back()) = last_departure_time;
                newpath.push_back({next_stop,NO_ROUTE,next_arrival_time});
                queue_path.push(newpath);
                discovered[next_stop] = next_arrival_time;
            }
        }
    }

    // if no route found, then empty vector should be returned
    path.clear();
    return path;

}

void Datastructures::add_walking_connections()
{
    // Replace this comment and the line below with your implementation
}


// The below are private auxiliary functions
int Datastructures::distance(Stop stop1, Stop stop2)
{
    int dx = stop1.stop_coord.x - stop2.stop_coord.x;
    int dy = stop1.stop_coord.y - stop2.stop_coord.y;
    int distance = floor(sqrt(dx*dx + dy*dy));
    return distance;

}
