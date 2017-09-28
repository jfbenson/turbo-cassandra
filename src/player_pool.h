#ifndef PLAYER_POOL_H
#define PLAYER_POOL_H

typedef std::unordered_map<string, player_t> player_pool_t;

bool player_pool_import(string filename);
void player_pool_filter();

#endif /* PLAYER_POOL_H */
