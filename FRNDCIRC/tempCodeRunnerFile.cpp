if (x == visit[x])
        return x;
    return find_set(visit[x]);