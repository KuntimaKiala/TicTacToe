#pragma once
#include <iostream>
#include <stdio.h>
#include <vector>
#include <memory>
#include <map>
#include <unordered_map>
#include <unordered_set>

namespace FromHeLL
{
    
    template <typename T> 
    using unique = std::unique_ptr<T>;

    template <typename T>
    using shared = std::shared_ptr<T>;
    
    template <typename T> 
    using weak = std::weak_ptr<T>;

    template <typename T>
    using List = std::vector<T>;

    template <typename keyType, typename valueType, typename Pr = std::less<keyType>> 
    using Map = std::map<keyType, valueType, Pr>;

    template <typename keyType, typename valueType, typename Hasher = std::hash<keyType>>
    using Dictionary = std::unordered_map<keyType, valueType, Hasher>;

    template <typename T>
    using Set = std::unordered_set<T>;

    typedef std::string String;
    #define LOG(M, ...) printf(M "\n", ##__VA_ARGS__)
}