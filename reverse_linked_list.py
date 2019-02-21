class Node(object):
    def __init__(self, value=None, next_node=None):
        self.value = value
        self.next_node = next_node
        
    def get_value(self):
        return self.value
        
    def get_next(self):
        return self.next_node
        
    def set_next(self, new_next):
        self.next_node = new_next
        
        
class LinkedList(object):
    def __init__(self, head):
        self.head = head
        
    def insert(self, value):
        new_node =  Node(value)
        new_node.set_next(self.head)
        self.head = new_node
        
    def print_list(self):
        current = self.head
        while(current):
            print(current.value)
            current = current.next_node
    
    def reverse_list(self):
        current = self.head
        prev = None
        while(current.next_node):
            Next = current.next_node
            current.next_node = prev
            prev = current
            current = Next
        current.next_node = prev
        self.head = current
        
        
    
my_head = Node(1)
my_list = LinkedList(my_head)
my_list.insert(2)
my_list.insert(3)
my_list.insert(4)
my_list.insert(5)
my_list.insert(6)

my_list.print_list()

my_list.reverse_list()

my_list.print_list()
