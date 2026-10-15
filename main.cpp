#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <stack>
#include "the_dedcition.hpp"
#include "vector_to_string_array.hpp"

void transpile(std::string the_dialouge, std::string name){
    text speach;
    std::string dialouge;
    for (char c: the_dialouge){
        if (!speach.is_escaping){
            if (c == '\\'){
                speach.line_dedictor(&dialouge);
            }
            else if (c == ':'){
                while (dialouge.at(dialouge.size() - 1) == ' '){
                    dialouge.pop_back();
                }

                if (std::find(speach.uniqe_speakers.begin(),speach.uniqe_speakers.end(),dialouge) == speach.uniqe_speakers.end()){
                    speach.add_error("unexcpted error: undefined user");
                }
               speach.speaker_dedictor(&dialouge);
            }
            else if (c == '@'){
                speach.is_escaping= true;
            }
            else if (c == '\t' || c == '\n'){
                continue;
            }
            else if (c == ';'){
                while (dialouge.at(dialouge.size() - 1) == ' '){
                    dialouge.pop_back();
                }

                speach.uniqe_speakers.push_back(dialouge);
                speach.speaker_dedictor(&dialouge);
            }
            else{
                dialouge.push_back(c);
            }
        }
        else{
            if (c == '\\'){
                dialouge.push_back(c);
            }
            else if (c == ':'){
                dialouge.push_back(c);
            }
            else if (c == '@'){
                dialouge.push_back(c);
            }
            else if (c == 't'){
                dialouge.push_back('\t');
            }
            else if (c == 'n'){
                dialouge.push_back('\n');
            }
            else if (c == ';'){
                dialouge.push_back(c);
            }
            else{
                speach.add_error("unexpected error: non existent escaped character");
            }
            speach.is_escaping = false;
        }

    }

    std::string first_part;
    while (name.at(name.size() - 1) == ' '){
        name.pop_back();
    }
    first_part = "class_name " + name + "\nextends Node";
    for (std::string s:speach.uniqe_speakers){
        first_part = first_part + "\nstatic var " + s + ":Texture2D";
    }
    
    first_part = first_part + "\nsignal interact\nvar input:StringName\n";
    first_part = first_part + "var lines:Array[String] = " + print_string_as_array(speach.lines);
    first_part = first_part + "\nvar speakers:Array[String] = " + print_string_as_array(speach.speakers);
    first_part = first_part + "\nvar uniuqe_speakers:Dictionary[String,Texture2D] = " + vector_to_dict(speach.uniqe_speakers) + "\nstatic func init(";
    for (std::string s:speach.uniqe_speakers){
        first_part = first_part + s + "_:Texture2D,";
    }
    first_part = first_part + ") -> void:";
    for (std::string s:speach.uniqe_speakers){
        first_part = first_part + "\n\t" + s + " = " + s + "_"; 
    }
    first_part = first_part + "\nfunc _input(event: InputEvent) -> void:\n\tif event.is_action_pressed(input):\n\t\tinteract.emit()\nstatic func play_dialouge(tree:SceneTree, line_label:RichTextLabel,speaker_label:RichTextLabel = null,speaker_image:TextureRect = null ,input_func:StringName = \"ui_accept\",speed:float = 1.0) -> void:\n\tvar new := " + name + ".new()\n\tnew.input = input_func\n\ttree.current_scene.add_child(new)\n\tnew.the_dialouge(line_label,speaker_label,speaker_image,speed)";
    
    const std::string SECOND_PART = "\nfunc the_dialouge(line_label:RichTextLabel,speaker_label:RichTextLabel = null,speaker_image:TextureRect = null,speed:float = 1.0,) -> void:\n\tline_label.show()\n\tif speaker_label:\n\t\tspeaker_label.show()\n\tif speaker_image:\n\t\tspeaker_image.show()\n\tfor i in lines.size(): #size bcs we dont just have lines we have synced arrays too\n\t\tline_label.visible_ratio = 0.0\n\t\tline_label.text = lines.get(i)\n\t\tif speaker_label:\n\t\t\tspeaker_label.text = speakers.get(i)\n\t\tif speaker_image:\n\t\t\tspeaker_image.texture = uniuqe_speakers.get(speakers.get(i))\n\t\tvar tw := create_tween()\n\t\ttw.tween_property(line_label,\"visible_ratio\",1,(line_label.text.length() * 0.1) * (speed ** -1))\n\t\tawait interact\n\t\tif line_label.visible_ratio == 1.0:\n\t\t\tcontinue\n\t\telse:\n\t\t\ttw.stop()\n\t\t\tline_label.visible_ratio = 1.0\n\t\tawait interact\n\tline_label.hide()\n\tif speaker_label:\n\t\tspeaker_label.hide()\n\tif speaker_image:\n\t\tspeaker_image.hide()\n\tqueue_free()";





    if (speach.gone_wrong){
        for (std::string error: speach.errors){
            std::cout << error << std::endl;
        }
    }
    else{

        std::cout << first_part + SECOND_PART << std::endl;
    }

    
}


int main(){
    transpile("sekmek;my fav @; goon \\karam;pp\\","ssssss");
    return 0;
}