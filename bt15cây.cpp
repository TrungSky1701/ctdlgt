/*Mục lục của một cuốn sách được lưu trữ dưới dạng một cây trong đó
 mỗi node có thể là chapter, section, subsection, subsubsection.  
a.Khai báo cấu trúc cây để biểu diễn cuốn sách. Các thông tin chứa
 ở mỗi node sinh viên tự đưa vào để đảm bảo các nội dung sau được 
 thực hiện:  
Xác định số chương của cuốn sách 
Tìm chương dài nhất của cuốn sách 
Thực hiện tìm một mục và xoá mục đó khỏi sách. Lưu ý cập nhật lại 
số trang của từng mục.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Khai báo cấu trúc Node biểu diễn trong cây
typedef struct TreeNode {
    char title[100]; // tiêu đề
    int pages; // số trang
    struct TreeNode** children; // con trỏ đến các nút con
    int child_count; // số lượng nút con
} TreeNode;

// Tạo một node mới
TreeNode* create_node(char* title, int pages) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    strcpy(node->title, title);
    node->pages = pages;
    node->children = NULL;
    node->child_count = 0;
    return node;
}

// Thêm một nút con vào nút cha
void add_child(TreeNode* parent, TreeNode* child) {
    parent->child_count++;
    parent->children = (TreeNode**)realloc(parent->children, parent->child_count * sizeof(TreeNode*));
    parent->children[parent->child_count - 1] = child;
}

// Đếm số chương của cuốn sách
int count_chapters(TreeNode* node) {
    if (node->child_count == 0) {
        return 1;
    }
    int count = 0;
    for (int i = 0; i < node->child_count; i++) {
        count += count_chapters(node->children[i]);
    }
    return count;
}

// Tìm chương dài nhất
TreeNode* find_longest_chapter(TreeNode* node, TreeNode* longest_node) {
    if (node->pages > longest_node->pages) {
        longest_node = node;
    }
    for (int i = 0; i < node->child_count; i++) {
        longest_node = find_longest_chapter(node->children[i], longest_node);
    }
    return longest_node;
}

// Tìm và xóa một mục theo tiêu đề
TreeNode* find_and_delete(TreeNode* node, char* title, int* pages) {
    if (strcmp(node->title, title) == 0) {
        *pages = node->pages;
        free(node->children);
        free(node);
        return NULL;
    }
    for (int i = 0; i < node->child_count; i++) {
        node->children[i] = find_and_delete(node->children[i], title, pages);
    }
    return node;
}

// Cập nhật lại số trang của các mục
void update_pages(TreeNode* node, int pages_change) {
    node->pages += pages_change;
    for (int i = 0; i < node->child_count; i++) {
        update_pages(node->children[i], pages_change);
    }
}

int main() {
    TreeNode* root = create_node("Cuốn sách", 0);
    TreeNode* chapter1 = create_node("Chương 1", 50);
    TreeNode* chapter2 = create_node("Chương 2", 30);
    TreeNode* section1 = create_node("Phần 1.1", 20);
    TreeNode* section2 = create_node("Phần 1.2", 30);

    add_child(root, chapter1);
    add_child(root, chapter2);
    add_child(chapter1, section1);
    add_child(chapter1, section2);

    // Số chương của cuốn sách
    printf("Số chương: %d\n", count_chapters(root));

    // Chương dài nhất của cuốn sách
    TreeNode* longest_chapter = find_longest_chapter(root, root);
    printf("Chương dài nhất: %s với %d trang\n", longest_chapter->title, longest_chapter->pages);

    // Tìm và xóa một mục
    int pages = 0;
    root = find_and_delete(root, "Phần 1.1", &pages);
    if (pages > 0) {
        update_pages(root, -pages);
    }

    return 0;
}
