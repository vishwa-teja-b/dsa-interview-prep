import java.util.*;

class Node{
    int data;
    Node left;
    Node right;
    Node(int data){
        this.data = data;
        left=null;
        right=null;
    }
}
class Pair{
    Node node;
    int diagonal;

    Pair(Node node, int diagonal){
        this.node = node;
        this.diagonal = diagonal;
    }
}

class Tree {
    public ArrayList<Integer> diagonal(Node root) {
        // add your code here.
        ArrayList<Integer> ans = new ArrayList<>();
        Queue<Pair> q = new LinkedList<>();
        q.add(new Pair(root,0));

        TreeMap<Integer, ArrayList<Integer>> map = new TreeMap<>();

        while(!q.isEmpty()){
            Pair current = q.poll();
            Node currentNode = current.node;
            int diagonal = current.diagonal;

            while(currentNode != null){
                if(map.get(diagonal) == null) map.put(diagonal, new ArrayList<>());
                map.get(diagonal).add(currentNode.data);
                
                if(currentNode.left != null) q.add(new Pair(currentNode.left, diagonal+1));
                currentNode = currentNode.right;
            }
        }

        for(ArrayList<Integer> al : map.values()){
            for(int val : al) ans.add(val);
        }
        return ans;
    }
}

public class DiagonalTreeTraversal {
    public static void main(String[] args) {
        Node root = new Node(8);

        root.left = new Node(3);
        root.right = new Node(10);

        root.left.left = new Node(1);
        root.left.right = new Node(6);

        root.right.right = new Node(14);

        root.left.right.left = new Node(4);
        root.left.right.right = new Node(7);

        root.right.right.left = new Node(13);
    }
}
