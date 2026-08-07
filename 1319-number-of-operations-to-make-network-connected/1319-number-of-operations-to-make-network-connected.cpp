# define ll long long
class DSU {
    vector<int> parent, size;
public:
    DSU(int n) : parent(n), size(n, 1) {
        iota(parent.begin(), parent.end(), 0); // parent[i] = i
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]); // path compression
        return parent[x];
    }

    bool unite(int x, int y) {
        int rx = find(x), ry = find(y);
        if (rx == ry) return false; // already connected

        if (size[rx] < size[ry]) swap(rx, ry); // union by size
        parent[ry] = rx;
        size[rx] += size[ry];
        return true;
    }

    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};


class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        ll m = connections.size();
        ll exc=0;
        ll comp = n;
        DSU dsu(n);
        for(auto it: connections){
            bool a = dsu.unite(it[0], it[1]);
            if(a==false){
                exc++;
            }
            else{
                comp--;
            }
        }
        if(exc >= comp-1){
            return comp-1;
        }
        else{
            return -1;
        }
    }
};