import java.util.Stack;
public class PathtoRoot {

    public static class Node {

        int data;
        Node left;
        Node right;


        Node(int data, Node left, Node right){
            this.data = data;
            this.left = left;
            this.right = right;
        }
    }
    
    public static class Pair{
        Node node; 
        int state;

        Pair(Node node, int state){
            this.node = node;
            this.state = state;
        }
    }

    public static void printRoottoLeaf(Node node){

        if(node == null){
            return;
        }

        int arr[] = new int[20];

        printPathImplementation(node, arr ,0);
    }


    public static void printPathImplementation(Node node, int[]arr, int index){

        if(node == null){
           return;
        }

        arr[index] = node.data;

        if(node.left == null && node.right == null){
            printArray(arr, index);
        } 

        printPathImplementation(node.left, arr, index+1);
        printPathImplementation(node.right, arr, index+1);

    }

    public static void printArray(int[]arr, int index){
        
        for(int i =0; i<= index;i++){
            System.out.println(arr[i]);
        }
        System.out.println();
    }



    public static void main(String[] args) {

        Integer[] arr = {50,25,12,null,null,37,30,null,null,null,75,62,null,70,null,null,87,null,null};

        Node root = new Node(arr[0], null, null);
        Pair rtp = new Pair(root, 1);

        Stack<Pair>st = new Stack<>();
        st.push(rtp);
        int idx = 0;

        while(st.size() > 0){
            Pair top = st.peek();
            if(top.state == 1){
                idx++;
                if(arr[idx]!= null){
                    top.node.left = new Node(arr[idx], null, null);
                    Pair lp = new Pair(top.node.left, 1);
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

        printRoottoLeaf(root);
        
    }
}