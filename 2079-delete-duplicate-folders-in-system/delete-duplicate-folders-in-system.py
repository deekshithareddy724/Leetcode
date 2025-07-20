class Solution:
    class Node:
        def __init__(self):
            self.children = {}
            self.del_flag = False

    def deleteDuplicateFolder(self, paths):
        root = self.Node()
        seen = defaultdict(list)

        # Step 1: Build the folder tree (Trie)
        for path in paths:
            node = root
            for folder in path:
                if folder not in node.children:
                    node.children[folder] = self.Node()
                node = node.children[folder]

        # Step 2: Serialize each subtree to identify duplicates
        def dfs(node):
            if not node.children:
                return ""
            serials = []
            for name in sorted(node.children):
                serials.append(name + "(" + dfs(node.children[name]) + ")")
            serial = "".join(serials)
            seen[serial].append(node)
            return serial

        dfs(root)

        # Step 3: Mark duplicate nodes
        for nodes in seen.values():
            if len(nodes) > 1:
                for node in nodes:
                    node.del_flag = True

        # Step 4: Collect all non-deleted paths
        res = []

        def collect(node, path):
            for name, child in node.children.items():
                if child.del_flag:
                    continue
                path.append(name)
                res.append(list(path))
                collect(child, path)
                path.pop()

        collect(root, [])
        return res