import sys
import os

def list_files(root="./", filter_func=None, is_include_root=False):
    assert os.path.isdir(root), "Invalid folder: %s" % root
    result = []
    for root_dir, sub_dir_list, files in os.walk(root):
        for f in files:
            fpath = os.path.join(root_dir, f)
            is_keep = filter_func(fpath) if filter_func else True
            if is_keep:
                if not is_include_root:
                    fpath = fpath.replace(root, "").strip("/")
                result.append(fpath)
            pass
        pass
    result = sorted(result)
    return result


if __name__ == "__main__":
    path = sys.argv[1]
    files = list_files(root=path,
                             filter_func=lambda x: True if x.endswith(
                                 '.mdx') else False,
                             is_include_root=False)
    print(files)
