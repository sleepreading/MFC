/*	����ÿһ�������������Ӧ�� ����汾, Ҳ��һ���� x,y,width,height ��Ӧ�� rect �汾
	GDI�汾,�ĸ����� x,y,width,height ͨ��Ϊ x1,y1,x2,y2
*/
Status DrawArc(
const Pen *pen,
INT x,
INT y,
INT width,
INT height,
REAL startAngle,	//�� x ��,��ʱ�뷽����ת�ĽǶ�
REAL sweepAngle);	//ɨ���ļн�

Status DrawPolygon(
const Pen *pen,
const Point *points,
INT *count
);

/*
��p1��p2���yֵ���,��Ϊˮƽ����Ľ���;
��p1��p2���xֵ���,��Ϊ��ֱ����Ľ���;
p1��p2���x��yֵ�������,��Ϊб�ԽǷ���Ľ���
Ϊ��ʵ�ֹ���,��õ��� Brush::SetWrapMode(WrapModeTileFlipX);
�����������Ĺ��캯��,������һ�����ζ�����������������;������תһ���Ƕ�
*/
LinearGradientBrush(p1, p2, col1, col2);