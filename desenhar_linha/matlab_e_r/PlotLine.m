prompt = {'Digite o eixo X1','Digite o eixo X2'};
dlgtitle = 'Input';
dims = [1 35];
definput = {'0','0'};
answer = inputdlg(prompt,dlgtitle,dims,definput);

prompt1 = {'Digite o eixo Y1','Digite o eixo Y2'};
dlgtitle1 = 'Input';
dims1 = [1 35];
definput1 = {'0','0'};
answer1 = inputdlg(prompt1,dlgtitle1,dims1,definput1);

plot([str2num(answer{1}),str2num(answer{2})],[str2num(answer1{1}),str2num(answer1{2})],'.-r');







