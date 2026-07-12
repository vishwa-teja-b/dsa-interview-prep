import java.util.*;

class Node {
    int data;
    Node left, right;
    Node(int val) {
        data = val;
        left = null;
        right = null;
    }
}

class Solution {
    public void alternateReverse(Node root) {
        // code here
        bfs(root);
        // return root;
    }

    private void bfs(Node root){
        Deque<Node> dq = new ArrayDeque<>();
        dq.addLast(root);

        // int level =is 0;
        // boolean isOddLevel = false;
        int level = 0;
        TreeMap<Integer, List<Node>> map = new TreeMap<>();

        while(!dq.isEmpty()){
            int size = dq.size();

            // if(level%2 == 1) map.put(level, new ArrayList<>());
            
            List<Node> oddLevelNodes = new ArrayList<>();

            for(int i=0;i<size;i++){
                Node current = dq.removeFirst();

                if(level%2 == 1) oddLevelNodes.add(current);

                if(current.left != null) dq.addLast(current.left);
                if(current.right != null) dq.addLast(current.right);
            }

            if(level%2 == 1) map.put(level, new ArrayList<>(oddLevelNodes));
            // isOddLevel = !isOddLevel; level
            level++;
        }

        for(List<Node> al : map.values()){
            
            int left = 0; int right = al.size()-1;

            while(left < right){
                int temp = al.get(left).data;
                al.get(left).data = al.get(right).data;
                al.get(right).data = temp;
                left++;
                right--;
            }
        }
    }
}

public class ReverseOddLevelsBFS {
    public static void main(String[] args) {
        Node root = new Node(1);
        root.left = new Node(2);
        root.right = new Node(3);

        root.left.left = new Node(42);
        root.left.right=  new Node(51);

        root.right.left = new Node(63);
        root.right.right = new Node(72);
    }
}
