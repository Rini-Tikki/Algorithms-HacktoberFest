import 'dart:collection'; 
void main() { 
   Queue queue = new Queue(); 
   print("Default implementation ${queue.runtimeType}"); 
   queue.addAll([10,12,13,14]); 
   for(var no in queue){ 
      print(no); 
   } 
}
