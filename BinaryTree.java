import java.util.Stack;

/**
 * BinaryTree
 */
public class BinaryTree {
   
   public static class Node {
        
        int data;
        Node left;
        Node right;

        Node(int data, Node left, Node right) {
            this.data = data;
            this.left = left;
            this.right = right;
        }
    }

    public static class Pair {
        Node node;
        int state;

        Pair(Node node, int state){
            
            this.node = node;
            this.state = state;
        }
    }



    //this function is to display the constructed binary tree from the array
    public static void display(Node node){
        if(node == null){
            return;
        }
        String str = "";
        str+= node.left == null?"." : node.left.data+ "";
        str+= " <- " + node.data + " -> ";
        str+= node.right == null?"." : node.right.data+ "";

        System.out.println(str);

        display(node.left);
        display(node.right);
    }


    // size is equal to the number of nodes in the whole tree structure 
    public static int size(Node node){
        if(node == null){
            return 0;
        }
        int ls=  size(node.left);
        int rs = size(node.right);

        return ls+rs+1;
    }

    // sum of the nodes present in the whole tree structure 
    public static int sum(Node node){

        if( node == null){
            return 0;
        }

        int ls = sum(node.left);
        int rs = sum(node.right);
        int ts = ls+rs+node.data;

        return ts;
    }


    //this function is to calculate the maximum of the all nodes
    public static int maximum(Node node){

        if(node == null){
            return Integer.MIN_VALUE;
        }

        int ls = maximum(node.left);
        int rs = maximum(node.right);

        int max = Math.max(node.data, Math.max(ls, rs));
        return max;
    }

    //this function is for the height calculation through edge traversal
    public static int height(Node node){

        if(node == null){
            return -1;
        }
        int lh = height(node.left);
        int rh = height(node.right);

        int max_h = Math.max(lh, rh) + 1;
        return max_h;
    }
    public static void main(String[] args) {
        Integer[] arr = {50,25,12,null,null,37,30,null,null,null,75,62,null,70,null,null,87,null,null};

        Node root = new Node(arr[0],null,null);
        Pair rootPair = new Pair(root,1);

        Stack<Pair>st = new Stack<>();
        st.push(rootPair);

        int idx = 0;

        while(st.size() > 0){
            Pair top = st.peek();
            if(top.state == 1){
               idx++;
               if(arr[idx] != null){
                   top.node.left = new Node(arr[idx],null,null);
                   Pair lp = new Pair(top.node.left,1);
                   st.push(lp);
               }
               else{
                   top.node.left = null;
               }
                 top.state++;

            }else if(top.state == 2){

                idx++;
                if(arr[idx] != null){
                    top.node.right = new Node(arr[idx],null,null);
                    Pair rp = new Pair(top.node.right,1);
                    st.push(rp);
                }
                else{
                    top.node.right = null;
                }
                  top.state++;

            }else{
                  st.pop();
            }
        }
        display(root);
        System.out.println(size(root)); 
        System.out.println(sum(root)); 
        System.out.println(maximum(root)); 
        System.out.println(height(root)); 

    }
    
}