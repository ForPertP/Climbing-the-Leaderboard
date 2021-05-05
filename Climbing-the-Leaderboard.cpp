vector<int> climbingLeaderboard(vector<int> ranked, vector<int> player)
{
    vector<int> ranks(player.size(), 1);
    int rank = 2;
    int n = ranked.size() - 1;
    
    for (int i = n; i > 0; --i)
    {
        if(ranked[i] < ranked[i-1])
        {
            rank++;
        }
    }
    
    for (size_t i = 0; i < player.size(); ++i)
    {
        while (player[i] >= ranked[n])
        {
            if(rank == 1)
            {
                i = player.size()-1;
                break;
            }
            
            if(ranked[n] != ranked[n-1])
            {
                rank--;
            }
            n--;
        }
        ranks[i] = rank;
    }
    
    return ranks;
}
