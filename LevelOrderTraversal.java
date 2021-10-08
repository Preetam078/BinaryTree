import java.util.ArrayDeque;
import java.util.Queue;
import java.util.Stack;


public class LevelOrderTraversal {


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

    //this function is all about the level order traversal
    public static void levelTraversal(Node node){
         
        Queue<Node>mq = new ArrayDeque<>();
        mq.add(node);
        while(mq.size() > 0){
            int count = mq.size();
            for(int i =0;i<count;i++){
              Node temp = mq.remove();
              System.out.println(temp.data);

              if(temp.left != null){
                  mq.add(temp.left);
              }
              if(temp.right != null){
                  mq.add(temp.right);
              }
            }
            System.out.println();
        }
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
        levelTraversal(root);
     
    }


}
