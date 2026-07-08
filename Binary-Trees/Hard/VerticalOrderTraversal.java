import java.util.*;

@SuppressWarnings("unused")
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class Tuple{
    int level;
    int vertical;
    TreeNode node;

    Tuple(int vertical, int level, TreeNode node){
        this.vertical = vertical;
        this.level = level;
        this.node = node;
    }
}
 
// LEVEL - ORDER BASED 
class Solution {
    public List<List<Integer>> verticalTraversal(TreeNode root) {
        Queue<Tuple> q = new LinkedList<>();
        q.add(new Tuple(0,0,root));

        // vertical --> map --> level --> priorityqueue

        TreeMap<Integer, TreeMap<Integer, PriorityQueue<Integer>>> map = new TreeMap<>();

        while(!q.isEmpty()){
            Tuple current = q.poll();
            int vertical = current.vertical;
            int level = current.level;
            TreeNode currentNode = current.node;

            if(map.get(vertical) == null){
                map.put(vertical, new TreeMap<>());
            }
            
            if(map.get(vertical).get(level) == null){
                map.get(vertical).put(level, new PriorityQueue<>());
            }

            map.get(vertical).get(level).add(currentNode.val);

            if(currentNode.left != null) q.add(new Tuple(vertical-1, level+1, currentNode.left));
            if(currentNode.right != null) q.add(new Tuple(vertical+1, level+1, currentNode.right));
        }

        List<List<Integer>> ans = new ArrayList<>();

        for(TreeMap<Integer, PriorityQueue<Integer>> innermap : map.values()){
            List<Integer> currentList = new ArrayList<>();
            for(PriorityQueue<Integer> pq : innermap.values()){
                while(!pq.isEmpty()) currentList.add(pq.poll());
            }

            ans.add(currentList);
        }

        return ans;
    }
}

public class VerticalOrderTraversal{
    public static void main(String[] args) {
        TreeNode root1 = new TreeNode(3);
        root1.left = new TreeNode(9);
        root1.right = new TreeNode(20);
        root1.right.left = new TreeNode(15);
        root1.right.right = new TreeNode(7);

        TreeNode root2 = new TreeNode(1);
        root2.left = new TreeNode(2);
        root2.right = new TreeNode(3);
        root2.left.left = new TreeNode(4);
        root2.left.right = new TreeNode(5);
        root2.right.left = new TreeNode(6);
        root2.right.right = new TreeNode(7);

        Solution sol = new Solution();

        List<List<Integer>> ans = sol.verticalTraversal(root1);

        System.out.println(ans);
    }
}