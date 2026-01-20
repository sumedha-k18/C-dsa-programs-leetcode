class Solution {
    public ArrayList<Integer> bfs(ArrayList<ArrayList<Integer>> adj) {

        ArrayList<Integer> bfs = new ArrayList<>();
        int n = adj.size();
        ArrayList<Boolean> vis = new ArrayList<>();
        for(int i = 0; i < n; i++)
            vis.add(false);
            Queue<Integer> que = new LinkedList<>();
            que.add(0);
            vis.set(0, true);
            while(!que.isEmpty()) {
                int node = que.poll();
                bfs.add(node);
                 for(Integer it : adj.get(node)) {
                    if(!vis.get(it)) {
                    vis.set(it, true);
                    que.add(it);
                }
            }
        }
        return bfs;
    }
}